#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;--i)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 4e18, MOD = 1e9+7;
const double eps = 1e-9;

int n;
deque<int> pos;
vb b;
int cnt = 0;
void do_move(int k){
    chkmin(k, (int)pos.size());
    cout<<k<<" ";
    loop(i,0,k){
        int x = pos.front();
        b[x] = 1;
        cout<<x+1<<" ";
        pos.pop_front();
    }
    cout<<endl;
    cnt+=k;
    int x; cin>>x; x--;
    loop(i,0,k){
        int ind = (i+x)%n;
        if (!b[ind]) continue;
        cnt--;
        b[ind]=0;
        pos.push_front(ind);
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    if (n<=3) return cout<<0<<endl,0;
    b.resize(n);
    int best = -1, k = 0;
    loop(i,1,n){
        int v = n - (n+i-1)/i - (i-1);
        if (v>best) best = v, k = i;
    }
    //cout<<"K: "<<k<<" "<<best<<endl;
    vvi tmp(k);
    loop(i,0,n){
        tmp[i%(k)].pb(i);
    }
    loop(i,1,k) for(auto ind:tmp[i]) pos.pb(ind);
    int last = cnt;
    while(cnt<=best){
        do_move(k);
        if (last == cnt) break;
        last = cnt;
    }
    cout<<0<<endl;
    return 0;
}
/*
color a
cls
g++ f.cpp -o a & a
1
*/