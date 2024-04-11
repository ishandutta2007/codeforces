#include <iostream>
#include <string>
using namespace std;
#define fori(v) for(int i=0; i<v; i++)
#define lli long long int
int main()
{
    int n;
    cin>>n;
    int arr[n];
    fori(n)
    cin>>arr[i];
    lli sum =0; 
    sum+=arr[0]+1;
    for(int i=1; i<n; i++)
    {
        sum+=max(0,arr[i-1]-arr[i])+1+max(0,arr[i]-arr[i-1])+1;
    }
    cout<<sum;
}