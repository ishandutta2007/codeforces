#include <bits/stdc++.h>
using namespace std;
const int N=2e5+8;
int a[N] ,b[N];

int main() {
    ios_base::sync_with_stdio(false);
    int n,i,j,k;
    cin>>n;
    int lowest = 0;
    unordered_map<int,int> index;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
        cin>>b[i];
    for(i=0;i<n;i++)
        index[a[i]]=i;
    for(i=0;i<n;i++)
    {
        int v=b[i];
        int wi = index[v];
        
        if(wi<lowest) {
            cout<<0<<" ";
        }
        
        else{
            cout<<(wi - lowest+1)<<" ";
            lowest = wi+1;
        }
        //cout<<"lowest and working index are :"<<lowest<<" "<<wi<<endl;
    }
    cout<<endl;
}