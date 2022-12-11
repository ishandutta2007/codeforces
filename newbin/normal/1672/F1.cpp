#include<bits/stdc++.h>
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define ll long long
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
int main(){
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        vector<int> a(n);
        map<int, vector<int> > pos;
        fors(i,0,n) cin>>a[i], pos[a[i]] .pb(i);
        vector<int> b(n, 0);
        queue<int> q; 
        auto it = --pos.end(); 
        for(int x:it->second) q.push(a[x]);
        for(it = pos.begin(); it != pos.end(); ++it){
             if(q.size() >= it->second.size()){
                 for(int x:it->second) b[x] = q.front(), q.pop(), q.push(a[x]);
             }else{
                 int len = q.size();
                 for(int i = 0; i < len; ++i) {
                     int x = it->second[i];
                     b[x] = q.front(); q.pop();
                 }
                 fors(i,0,it->second.size()) q.push(it->first);
             }
            //  cout<<"---i:"<<it->first<<endl;
            //  fors(i,0,n) cout<<b[i]<<" "; cout<<endl;
        }
        fors(i,0,n) {
            if(b[i] == 0) b[i] = q.front(), q.pop();
            cout<<b[i]<<" ";
        }cout<<endl;
        
    }
    return 0;
}