#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<int,char> M[200009];
map<int,int> C[200009];
ll odd,even;
void ad(int x, int y, char a, char b){
    if(a == b) even++;
    odd++;
}
void rem(int x, int y, char a, char b){

    if(a == b) even--;
    odd--;
}


main(){
     int n,m;
     cin >> n >> m;
     while(m--){
        char t;
        cin>>t;
        if(t == '+'){
            int u,v;
            char c;
            cin>>u>>v>>c;
            M[u][v] = c;
            if(M[v][u]) ad(u, v, M[u][v],M[v][u]);
        }
        if(t == '-'){
            int u,v;
            cin>> u>>v;
            if(M[v][u])
                rem(u,v,M[u][v],M[v][u]);
            M[u][v] = 0;
        }
        if(t == '?'){
            int k;
            cin>>k;
            if(k%2 == 0 && even) cout<<"YES"<<endl;
            else if(k% 2 ==1 && odd) cout<<"YES"<<endl; else
            cout <<"NO"<<endl;
        }
     }

}