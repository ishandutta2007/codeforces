#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <ctime>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>

#define mp make_pair
#define pb push_back

using namespace std;

typedef long long int64;
typedef long double ld;

char have[255];

int main(){
    string s;
    getline(cin,s);
    for (int i=0;i<s.size();i++)
    have[s[i]]++;
    getline(cin,s);
    for (int i=0;i<s.size();i++)
    have[s[i]]--;
    for (char i='A';i<='Z';i++)
    if (have[i]<0){
        printf("NO\n");
        return 0;
    }
    for (char i='a';i<='z';i++)
    if (have[i]<0){
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    return 0;  
}