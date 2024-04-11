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

map<string,int> a;

int main(){
    int n;
    cin>>n;
    string s;
    for (;cin>>s;){
    if (a.find(s)==a.end()) a[s]=0;
    a[s]++;
    }
    if (a.size()==1 || a.begin()->second > (--a.end())->second)
    cout<<a.begin()->first<<endl;
    else
    cout<<(--a.end())->first<<endl;
    return 0;  
}