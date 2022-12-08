#include<bits/stdc++.h>
using namespace std;
int q[1009],p[1009],C[1009];
int a[1009][1009];
int P(int x){
    if(x == p[x]) return x;
    p[x] = P(p[x]);
    return p[x];
}
main(){
    vector<pair<int, pair<int,int> > > v;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        p[i] = i, q[i] = i;
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(i == j) C[i] = a[i][j];
            else {
                v.push_back({a[i][j], {i,j}});
            }
        }
    }
    sort(v.begin(),v.end());
    int N = n;
    for(int i = 0; i <v.size(); i++){
        int x = v[i].second.first,y  =v[i].second.second, c = v[i].first;
        x = P(x); y = P(y);
        if(x == y) continue;
        if(C[x] == c) q[y]=x,p[y] = x; else
        if(C[y] == c) q[x] = y, p[x] = y; else{
            N++;
            p[N] = N; q[N] = N;
            C[N] = c;
            q[x] = N, p[x] = N, q[y] = N, p[y] = N;
        }
    }
    cout<<N<<endl;
    for(int i = 1; i <= N; i++){
        cout << C[i]<<" ";
    }
    cout<<endl;
    cout<<N<<endl;
    for(int i= 1; i < N; i++){
        cout <<i<<" "<<q[i]<<endl;
    }

}