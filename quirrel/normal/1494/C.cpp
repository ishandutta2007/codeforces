#include<bits/stdc++.h>
using namespace std;
map<int,int> M;
int cnt(int x, vector<int> &b){
    int l = 0, r = b.size();
    while(l < r){
        int mid  =(l+r)/2;
        if(b[mid] <= x) l =mid+1;
        else r = mid;


    }
    return l;
}
int solve(vector<int> a, vector<int> b){

    M.clear();
    vector<pair<int,int> > v;
    for(int x : b){
        v.push_back({x,1});
        M[x] = 1;

    }
    for(int x : a){
        v.push_back({x,-1});
    }
    sort(v.begin(),v.end());
    int ans = 0, x = 0, z = a.size();
    for(int i = v.size()- 1; i >= 0; i--){
        int y = v[i].first;
        int l = y - z + 1;
        ans = max(ans, cnt(y,b ) - cnt(l-1,b) + x);
        if(v[i].second == -1){
            z--;
            if(M[y] == 1) x++;
        }
    }
    return ans;
}
main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> na,pa,nb,pb;
        for(int i = 1; i <= n; i++){
            int a;
            cin >> a;
            if(a < 0) na.push_back(-a);
            else pa.push_back(a);

        }
        for(int i = 1; i <= m; i++){
             int a;
            cin >> a;
            if(a < 0) nb.push_back(-a);
            else pb.push_back(a);

        }
        reverse(nb.begin(),nb.end());
        reverse(na.begin(),na.end());
        cout << solve(na, nb) + solve(pa, pb)<<endl;

    }

}