#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

string s1,s2;
int b1[30],b2[30];
int i,j;
bool bisa;
int banyak;

int main()
{
    cin >> s1 >> s2;
    if (s1.length()<s2.length())
        printf("0\n");
    else
    {
        for (i=0;i<s2.length();i++)
            b2[s2[i]-'a']++;
        for (i=0;i<s2.length();i++)
            if (s1[i]>='a' && s1[i]<='z')
                b1[s1[i]-'a']++;
        bisa=true;
        for (i=0;i<26;i++)
            if (b1[i]>b2[i])
                bisa=false;
        if (bisa)
        {
     //       printf("0\n");
            banyak++;
        }
        for (i=s2.length();i<s1.length();i++)
        {
            if (s1[i]>='a' && s1[i]<='z')
                b1[s1[i]-'a']++;
            if (s1[i-s2.length()]>='a' && s1[i-s2.length()]<='z')
                b1[s1[i-s2.length()]-'a']--;
            bisa=true;
            for (j=0;j<26;j++)
                if (b1[j]>b2[j])
                    bisa=false;
            if (bisa)
            {
              //  printf("%d\n",i-s2.length());
                banyak++;
            }
        }
        printf("%d\n",banyak);
    }
    
    
}