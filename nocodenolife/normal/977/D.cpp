#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

struct Pairs
{
  ll num;
  ll pow_three;
};
typedef struct Pairs pr;

bool waytosort(pr a, pr b)
{
    if(a.pow_three == b.pow_three)
    {
        return a.num<b.num;
    }
    else
    {
        return a.pow_three>b.pow_three;
    }
}

int main()
{
    ll n;
    cin>>n;
    pr arr[n];
    
    for(int i=0;i<n;i++)
    {
        ll k;
        cin>>k;
        arr[i].num = k;
        ll temp = 0;
        while(k%3==0)
        {
            k/=3;
            temp++;
        }
        arr[i].pow_three = temp;
    }
    sort(arr,arr+n,waytosort);
    
    for(int i=0;i<n;i++)
    {
        cout<<arr[i].num<<" ";
    }
    cout<<endl;

    return 0;
}