#include<bits/stdc++.h>

using namespace std;

int main(){
    int T; cin>>T;
    while (T--){
        int n; string st;
        cin>>n>>st;
        string name="Timru";
        bool flag=0;
        do{
            if (st==name) flag=1;
        }while (next_permutation(name.begin(),name.end()));
        cout<<(flag?"YES\n":"NO\n");
    }

    return 0;
}