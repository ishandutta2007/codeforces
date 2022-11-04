#include <iostream>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int k,n;
    cin>>k;
    for(int i=0;i<k;++i){
        cin>>n;
        long long  tmp,s=0;
        for(int j=0;j<n;++j)
        {
            cin>>tmp;
            s+=tmp;
        }
        s=(s+n-1)/n;
        cout<<s<<endl;
    }
    return 0;
}