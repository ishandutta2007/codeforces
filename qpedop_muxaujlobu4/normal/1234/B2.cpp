#include <iostream>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int b[200001];
int main(){
    ios_base::sync_with_stdio(false);
    int n,k;
    map<int,int> a;
    cin>>n>>k;
    int hight=200000;
    for(int i=0;i<n;++i){
        int id;
        cin>>id;
        if(a[id]==0&&hight+k>200000){
            ++a[id];
            b[hight--]=id;
        }
        else{
            if(a[id]==0){
                --a[b[hight+k]];
                ++a[id];
                b[hight--]=id;
            }
        }
    }
    int c=min(k,200000-hight);
    ++hight;
    cout<<c<<endl;
    for(int i=hight;i<hight+c;++i)
        cout<<b[i]<<" ";
    return 0;
}