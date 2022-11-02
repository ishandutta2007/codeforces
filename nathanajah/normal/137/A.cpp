#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

string s;
int banyak;
int kali;
int i;

int main()
{
    cin >> s;
    banyak=1;
    for (i=1;i<s.length();i++)
    {
      //  cout << banyak << " " << kali << "\n";
        if (banyak==5)
        {
            kali++;
            banyak=1;
        }
        else if (s[i]==s[i-1])
        {
            banyak++;
        }
        else
        {
            kali++;
            banyak=1;
        }
    }
    kali++;
    printf("%d\n",kali);
}