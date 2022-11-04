#include <iostream>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int a[200001];
int Find (int x){
if(a[x]==x)return x;
int tmp = Find(a[x]);
a[x] =tmp;
return tmp;
}
int main(){
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n;++i)
        a[i]=i;
    for(int i=0;i<m;++i){
        int tmp1,tmp2,tmpred1,tmpred2;
        cin>>tmp1>>tmp2;
        tmpred1=Find(tmp1);
        tmpred2=Find(tmp2);
        if(tmpred1>tmpred2)a[tmpred2]=tmpred1;
        else a[tmpred1]=tmpred2;
    }
    int k=0;
    for(int i=1;i<n;++i){
        int pred1,pred2;
        pred1=Find(i);
        pred2=Find(i+1);
        if(pred1!=pred2&&pred1!=i){
            ++k;
        if(pred1>pred2)a[pred2]=pred1;
        else a[pred1]=pred2;
        }
    }
    cout<<k;
    return 0;
}