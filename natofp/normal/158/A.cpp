#include <iostream>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int wynik=0;
    int x;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        if(i==k) x=a;
        if((i<=k && a>0 )|| (i>k && a==x && a!=0)) wynik++;
    }
    cout<<wynik;
    return 0;
}