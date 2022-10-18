#include <iostream>

using namespace std;

int main()
{
    char a1,a2,a3,a4,b1,b2,b3,b4;
    int ans=0;

    cin >> a1 >> a2 >> a3 >> a4 >> b1 >> b2 >> b3 >> b4;


    for (int i=0;i<1000;i++)
    {
    if (a1==b1 && a2==b2 && a3==b3 && a4==b4) ans=1;
    if (a1=='X')
    {
        a1=a3;
        a3='X';
    }
    else if (a2=='X')
    {
        a2=a1;
        a1='X';
    }
    else if (a3=='X')
    {
        a3=a4;
        a4='X';
    }
    else if (a4=='X')
    {
        a4=a2;
        a2='X';
    }
    }

    if (ans==1) cout << "YES";
    else cout << "NO";

    return 0;
}