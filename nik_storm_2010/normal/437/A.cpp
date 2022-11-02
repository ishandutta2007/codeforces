#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
    int a[4], nom[4];
    for (int i = 0; i < 4; i++)
    {
        string s;
        getline(cin, s);
        a[i] = s.length() - 2;
        nom[i] = 65 + i;
    }
    for (int i = 0; i < 4; i++) for (int j = i + 1; j < 4; j++) if (a[i] > a[j]) swap(a[i], a[j]), swap(nom[i], nom[j]);
    if (a[0] * 2 <= a[1] && a[2] * 2 <= a[3])
    {
        printf("C");
        return 0;
    }
    if (a[0] * 2 <= a[1])
    {
        printf("%c", nom[0]);
        return 0;
    }
    if (a[2] * 2 <= a[3]) printf("%c", nom[3]); else printf("C");
    return 0;
}