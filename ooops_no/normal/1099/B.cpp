#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ll a;
	cin>>a;
	ll mns=INT_MAX;
	ll i=1;
	while(i<=sqrt(a)+5){
        if(a%i==0){
            mns=min(mns,i+a/i);
        }
        else{
            mns=min(mns,i+a/i+1);
        }
        i++;
	}
	cout<<mns;
}