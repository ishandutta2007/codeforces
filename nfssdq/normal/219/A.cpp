#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <locale>
#include <vector>
#include <cassert>
#include <climits>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <iterator>
#include <typeinfo>
#include <valarray>
#include <algorithm>
#include <functional>

using namespace std;

#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define LL long long
#define inf INT_MAX/2
#define mod 1000000007
#define PI 2.0*acos(0.0)
#define vsort(v) sort(v.begin(),v.end())
int ar[26];
char pp[1001];
char pr[1001];
main()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    cin>>a;
    scanf("%s",pp);
    b=0;
    for(x=0;x<strlen(pp);x++)ar[pp[x]-'a']++;
    for(x=0;x<26;x++)
    {
        if(ar[x]%a!=0)
        {
            cout<<-1<<endl;
            return 0;
        }
        for(y=0;y<(ar[x]/a);y++)pr[b++]=x+'a';
    }
    for(x=0;x<a;x++)
    {
        printf("%s",pr);
    }
    cout<<endl;
}