#include <iostream>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    vector <int> a(k,-1);
    for(int i=0;i<n;++i){
        int id;
        cin>>id;
        bool ok=false;
        for(int j=0;j<k;++j)
            if(a[j]==id)ok=true;
        if(ok)continue;
        for(int j=k-2;j>=0;--j)
            a[j+1]=a[j];
        a[0]=id;
    }
    int c=0;
    for(int i=0;i<k;++i)
        if(a[i]!=-1)++c;
    cout<<c<<endl;
    for(int i=0;i<k;++i)
        if(a[i]!=-1)cout<<a[i]<<" ";
    return 0;
}