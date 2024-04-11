#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char a[101]; char b[101];
    cin>>a; 
    cin>>b; 
    int n = (int)strlen(a);
    for(int i=0;i<n;i++)
    {
        if (a[i] == b[i]) cout << "0"; else cout << "1";
    }

    return 0;
}