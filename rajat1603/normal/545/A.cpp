#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
const int N = 101;
int n;
bool b[N]={0};
int main(){
    cin>>n;
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=n;++j){
            int temp;
            cin>>temp;
            if(temp==1){
                b[i]=1;
            }
            if(temp==2){
                b[j]=1;
            }
            if(temp==3){
                b[i]=1;
                b[j]=1;
            }
        }
    }
    int count = 0;
    for(int i = 1;i<=n;++i){
        if(b[i]==0){
            count++;
        }
    }
    cout<<count<<endl;
    for(int i = 1;i<=n;++i){
        if(b[i]==0){
            cout<<i<<" ";
        }
    }
}