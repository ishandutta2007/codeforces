#include<bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
//#define abs(a) ((a)>0?a:-(a))
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF=4e18;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q; cin>>n>>q;
    vi a(n);
    ii m={-INF,-1};
    loop(i,0,n){
        cin>>a[i];
        chkmax(m,mp(a[i],i));
    }
    vector<ii> p_ans(m.y);
    deque<int> dq;
    loop(i,0,n) dq.push_back(a[i]);
    int p,r;
    loop(i,0,m.y){
        p=*dq.begin();
        dq.pop_front();
        r=*dq.begin();
        dq.pop_front();
        dq.push_back(min(p,r));
        dq.push_front(max(p,r));
        p_ans[i]=mp(p,r);
    }
    dq.pop_front();
    vi na(n-1);
    loop(i,0,n-1){
        na[i]=*dq.begin();
        dq.pop_front();
    }
    loop(i,0,q){
        cin>>p;
        if (p>m.y){
            cout<<m.x<<" "<<na[(p-m.y-1)%(n-1)]<<endl;
        }
        else{
            cout<<p_ans[p-1].x<<" "<<p_ans[p-1].y<<endl;
        }
    }
    return 0;
}
/*
5 9
1 4 3 5 2
1
2
3
4
5
6
7
8
9
*/