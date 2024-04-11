#include <bits/stdc++.h>
using namespace std;

char wcz1[5];
char wcz2[5];

int czy;

vector <char> jed, dwa;

int main()
{
    scanf("%s%s", wcz1, wcz2);
    if (wcz1[0]=='A')
    czy^=1;
    if (wcz1[0]!='X' && czy)
    jed.push_back(wcz1[0]);

    if (wcz1[1]=='A')
    czy^=1;
    if (wcz1[1]!='X' && czy)
    jed.push_back(wcz1[1]);

    if (wcz2[1]=='A')
    czy^=1;
    if (wcz2[1]!='X' && czy)
    jed.push_back(wcz2[1]);

    if (wcz2[0]=='A')
    czy^=1;
    if (wcz2[0]!='X' && czy)
    jed.push_back(wcz2[0]);

    if (wcz1[0]=='A')
    czy^=1;
    if (wcz1[0]!='X' && czy)
    jed.push_back(wcz1[0]);

    if (wcz1[1]=='A')
    czy^=1;
    if (wcz1[1]!='X' && czy)
    jed.push_back(wcz1[1]);

    if (wcz2[1]=='A')
    czy^=1;
    if (wcz2[1]!='X' && czy)
    jed.push_back(wcz2[1]);

    if (wcz2[0]=='A')
    czy^=1;
    if (wcz2[0]!='X' && czy)
    jed.push_back(wcz2[0]);



    scanf("%s%s", wcz1, wcz2);
    if (wcz1[0]=='A')
    czy^=1;
    if (wcz1[0]!='X' && czy)
    dwa.push_back(wcz1[0]);

    if (wcz1[1]=='A')
    czy^=1;
    if (wcz1[1]!='X' && czy)
    dwa.push_back(wcz1[1]);

    if (wcz2[1]=='A')
    czy^=1;
    if (wcz2[1]!='X' && czy)
    dwa.push_back(wcz2[1]);

    if (wcz2[0]=='A')
    czy^=1;
    if (wcz2[0]!='X' && czy)
    dwa.push_back(wcz2[0]);

    if (wcz1[0]=='A')
    czy^=1;
    if (wcz1[0]!='X' && czy)
    dwa.push_back(wcz1[0]);

    if (wcz1[1]=='A')
    czy^=1;
    if (wcz1[1]!='X' && czy)
    dwa.push_back(wcz1[1]);

    if (wcz2[1]=='A')
    czy^=1;
    if (wcz2[1]!='X' && czy)
    dwa.push_back(wcz2[1]);

    if (wcz2[0]=='A')
    czy^=1;
    if (wcz2[0]!='X' && czy)
    dwa.push_back(wcz2[0]);

    if (jed==dwa)
    printf("YES\n");
    else
    printf("NO\n");
    return 0;
}