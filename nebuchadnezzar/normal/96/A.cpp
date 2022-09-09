#include <iostream>
using namespace std;
string a;

int str_len(string a)
{
    a = a + "5";
    int i;
    for(i = 0; a[i] != '5'; ++i)
    {
        i = i;
    }
    return i;
}
int main()
{
    cin >> a;
    /*cout << len_vec(a);*/
    int i, nump = 1;
    char pp = a[0];
    for(i = 1; i < str_len(a); ++i)
    {
        if(pp == a[i])
        {
            ++nump;
        }
        else
        {
            nump = 1;
        }
        pp = a[i];
        if(nump >= 7)
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}