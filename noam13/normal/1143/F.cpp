#include<bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define pb push_back
#define x first
#define y second
#define loop(i,s,e) for(int i=s;i<e;i++)
#define abs(a) ((a)>0?a:-(a))
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF=4e18;

ii p0;
// dis^2 between p1 and p2
int distSq(ii p1, ii p2){
    return (p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y);
}

// 0 -> p, q and r are colinear
// 1 -> Clockwise
// -1 -> Counterclockwise
int orientation(ii p, ii q, ii r){
    int val = (q.x-p.x) * (r.y-q.y) - (r.x-q.x) * (q.y-p.y);
    //(q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // colinear
    return (val > 0)? -1: 1; // clock or counterclock wise
}

// p1 < p2
bool compare(ii p1, ii p2){
   int o = orientation(p0, p1, p2);
   if (o == 0) return (distSq(p0, p2) >= distSq(p0, p1));
   return (o == 1);
}


vector<ii> convexHull(vector<ii> p){
   // Find the lowest point
    int ymin = p[0].y, mini = 0;
    loop(i,0,p.size()){
        int y = p[i].y;
        if ((y < ymin) || (ymin == y && p[i].x < p[mini].x)){
            ymin = y;
            mini = i;
        }
    }
    swap(p[0], p[mini]);
    p0 = p[0];
    //sort points
    sort(p.begin()+1, p.end(), compare);
    vector<ii> sol(0);
    sol.pb(p[0]);
    sol.pb(p[1]);
    sol.pb(p[2]);
   // Process remaining n-3 points
    loop(i, 3, p.size()){
        while (sol.size()>1 && orientation(sol[sol.size()-2], sol[sol.size()-1], p[i]) != 1){
            sol.pop_back();
        }
        sol.pb(p[i]);
    }
    return sol;
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vector<ii> p(n);
    loop(i,0,n){
        cin>>p[i].x>>p[i].y;
        p[i].y-=p[i].x*p[i].x;
    }
    sort(p.begin(),p.end());
    vector<ii> sol;
    loop(i, 0, p.size()){
        if(i<n-1 && p[i].x==p[i+1].x) continue;
        while (sol.size()>1 && orientation(sol[sol.size()-2], sol[sol.size()-1], p[i]) != 1){
            sol.pop_back();
        }
        sol.pb(p[i]);
    }
    cout<<(sol.size()-1)<<endl;

    /*p=convexHull(p);
    int ind=0,cnt=0;
    for(;ind<p.size()-1 && p[ind].x>=p[ind+1].x;ind++);
    for(;ind<p.size()-1 && p[ind].x<p[ind+1].x;ind++,cnt++);
    cout<<cnt<<endl;*/
    return 0;
}
/*
9
0 0
1 3
2 2
3 1
2 4
4 4
3 3
3 2
1 5
*/