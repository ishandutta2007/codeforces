#include <iostream>
using namespace std;
const int maxn=600050;
bool table[20][maxn];
int main(){
    ios_base::sync_with_stdio(false);
    int n, m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        table[0][a]=true;
    }
    for(int i=maxn-1; i>=0; i--)
        for(int j=1; j<=19&&i+(1<<j)<maxn; j++)
            table[j][i]=table[j-1][i]&table[j-1][i+(1<<j-1)];
    int cur=0;
    for(int i=0; i<m; i++){
        int curr=0, res=0, q;
        cin>>q;
        cur^=q;
        for(int j=19; j>=0; j--){
            int pos1=curr, pos2=curr+(1<<j);
            if(cur&(1<<j)) swap(pos1, pos2);//pos1j
            if(table[j][pos1]){
                curr=pos2;
                res+=1<<j;
            }else{
                curr=pos1;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}