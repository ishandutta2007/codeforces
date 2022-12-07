#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;


int main(){
    
    ll w,l;
    
    cin>>w>>l;
    ll logs[w];
    ll summed[w];
    cin>>logs[0];
    summed[0] = logs[0];
    for(ll i=1;i<w-1;i++){
        cin>>logs[i];
        summed[i]=summed[i-1]+logs[i];   
    }
    
    ll answer = summed[l-1];
    
    for(ll i=l;i<w-1;i++)
    {
        answer=min(answer,summed[i]-summed[i-l]);
    } 
    cout<<answer<<endl;
    return 0;
}