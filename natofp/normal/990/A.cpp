#include <iostream>

using namespace std;

int main()
{
    long long int n,m;
    int a,b;
    cin>>n>>m>>a>>b;
    long long int wynik=n%m;
    cout<<min(b*wynik,(m-wynik)*a);

    return 0;
}