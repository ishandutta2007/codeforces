#include <iostream>
#include <string>
#include <map>
using namespace std;
#define fori(v) for(int i=0; i<v; i++)
#define lli long long int
#define mp make_pair
#define ff first
#define ss second
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string a;
    cin>>a;
    int n = a.length();
    int left =0;
    int right=n-1;
    int arr[n];
    fori(a.length())
    {
        if(a[i]=='l')
        {
            arr[right] = i+1;
            --right;
        }
        else
        {
            arr[left] = i+1;
            ++left;
        }
    }
    fori(n)
    cout<<arr[i]<<endl;
}