#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
    
    ll n,k;
    cin>>n>>k;
    
    ll p[n];
    ll answers[256];
    
    for(ll i=0;i<256;i++)
    {
        answers[i] = -1;
    }
    for(ll i=0;i<n;i++)
    {
        cin>>p[i];
        if(answers[p[i]]!=-1)
            continue;
        ll leas = p[i] - k +1;
        if(leas<0)
            leas =0;
        
        ll idx = p[i];
        while(idx>=leas)
        {
            if(answers[idx]!=-1)
                break;
            idx--;
        }
        
        if(idx==leas-1)
        {
            for(ll j=leas;j<=p[i];j++)
            {
                answers[j]=leas;
            }
            continue;
        }
        ll count=0;
        ll temp = idx;
        while(temp>=0)
        {
            if(answers[temp]==answers[idx])
            {
                count++;
                temp--;
            }
            else
            {
                break;
            }
        }
        ll rem = k-count;
        if(p[i]<=idx+rem)
        {
            for(ll j=idx+1;j<=p[i];j++)
            {
                answers[j]=answers[idx];
            }
            continue;
        }
        else
        {
            for(ll j=idx+1;j<=p[i];j++)
            {
                answers[j]=idx+1;
            }
        }
    }
    for(ll i=0;i<n;i++)
    {
        cout<<answers[p[i]]<<" ";
    }
    cout<<endl;
    return 0;
}