#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

const int MAX = 100005;

int N;
char S [MAX];
map <char, int> occur;

int main ()
{
    scanf ("%s", S);
    N = strlen (S);

    for (int i = 0; i < N; i++)
        occur [S [i]]++;

    long long total = 0;

    for (map <char, int> :: iterator it = occur.begin (); it != occur.end (); it++)
        total += (long long) it->second * it->second;

    cout << total << '\n';
    return 0;
}