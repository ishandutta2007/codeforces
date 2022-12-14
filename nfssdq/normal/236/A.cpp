#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <typeinfo>
#include <locale>
#include <iterator>
#include <valarray>
#include <complex>
#include <climits>

using namespace std;

#define ULL unsigned long long
#define LL long long
#define inf INT_MAX
#define PI 2.0*acos(0.0)
#define vi vector<int>
#define vl vector<long long>
#define pdd pair<int,int>
#define pll pair<long long,long long>
#define mp make_pair
#define mdd map<int,int>
#define mod 1000000007
#define xx first
#define yy second
#define vsort(v) sort(v.begin(),v.end())
#define cas(a) printf("Case %d:\n",a)
#define pb push_back

int pp[30];
main()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    char ps[1001];
    scanf("%s",ps);
    a=0;
    for(x=0;x<strlen(ps);x++)pp[ps[x]-'a']=1;
    for(x=0;x<30;x++)a+=pp[x];
    if(a%2==0)cout<<"CHAT WITH HER!\n";
    else cout<<"IGNORE HIM!"<<endl;
}