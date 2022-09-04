#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
ll MOD=1e9+7;
#define INF 2*1e9
#define N 410000
using namespace std;
main(){
    int n;
    cin>>n;
    pii p[N];
    queue<int> q;
    rep(i,n){
        string s;
        int a;
        cin>>s;
        scanf("%d",&a);
        int b,c;
        if(s[1]=='D'){
            p[i]={a,0};
        }
        else {
            p[i]={a,1};q.push(a);
        }
    } 
    pqg p1;pq p2;
    ll ans=1;
    int mem=0;
    rep(i,n){
        if(q.empty()){
            int m,M;
            if(!p1.empty()) M=p1.top();
            else M=INF;
            if(!p2.empty()) m=p2.top();
            else m=0;
            int count=0;
            while(i!=n){
                int a=p[i].first;
                if(a<M&&a>m) count++;
                i++;
            }
            ans=ans*(count+1)%MOD;
        }
        if(p[i].second){
            int a=q.front();
            q.pop();
            if(!p2.empty()&&a<p2.top()){
                cout<<0;return 0;
            }
            if(!p1.empty()&&a>p1.top()){
                cout<<0;return 0;
            }
            if(mem){
                mem=0;ans=ans*2%MOD;
            }
            if(!p1.empty()&&p1.top()==a){
                p1.pop();
            }
            if(!p2.empty()&&p2.top()==a){
                p2.pop();
            }
        }
        else{
            int a=p[i].first;
            if(a<q.front()){
                p2.push(a);
            }
            else if(q.front()==a){
                mem=1;
            }
            else{
                p1.push(a);
            }
        }
    }
    cout<<ans;
    return 0;
}