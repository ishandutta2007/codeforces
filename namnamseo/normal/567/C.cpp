#include <iostream>
#include <map>

using namespace std;

int n,k;

map<int,long long> m[4];

int data[200010];

int main()
{
    cin>>n>>k;
    int i,j;
    for(i=0;i<n;++i){
        cin>>data[i];
        if(data[i]%k == 0) for(j=3;j>=2;--j) if(m[j-1].find(data[i]/k)!=m[j-1].end()) m[j][data[i]]+=m[j-1][data[i]/k];
        ++m[1][data[i]];
    }
    long long ans=0;
    for(auto it=m[3].begin(); it!=m[3].end();++it) ans+=it->second;
    cout<<ans;
    return 0;
}