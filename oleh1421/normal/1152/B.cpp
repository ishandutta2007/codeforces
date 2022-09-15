#include <iostream>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
vector<int>res;
int c=0;
void f(int x){
     if ((x&(x+1))==0) return;
     if ((x&(x-1))==0){
         c=1;
         return;
     }
     vector<int>v;
    int a=x;
     while (a){
        v.push_back(a%2);
        a/=2;
     }
     for (int i=(int)v.size()-1;i>=0;i--){

        if (v[i]==1) {
            res.push_back(i+1);
            x^=((1<<(i+1))-1);
            x++;
            f(x);
            return;
        }
     }
}
int main()
{
    int x;cin>>x;
    if ((x&(x-1))==0){
        int cnt=0;
        while (x>1){
            x/=2;
            cnt++;
        }
        cout<<1<<endl<<cnt;
        return 0;
    }
    f(x);
    cout<<res.size()*2-c<<endl;
    for (auto i:res) cout<<i<<" ";
    return 0;
}