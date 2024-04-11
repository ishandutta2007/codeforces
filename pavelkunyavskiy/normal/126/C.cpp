#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long ll;
typedef long double ld;

bool conv1[2100];
bool conv2[2100];

int cnt;

char c[2100][2100];


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  int n;
  gets(c[0]);
  sscanf(c[0],"%d",&n);
  for (int i = 0; i < n; i++)
    gets(c[i]);


  for (int i = 0; i < n; i++)
    for (int j = n-1; j > i; j--){

        if ((c[i][j] == '1') ^ conv1[i] ^ conv2[j]){
            cnt++;
            conv1[i] ^= 1;
            conv2[j] ^= 1;
        }       
    }

  for (int i = 0; i < n; i++)
    if (conv1[i] ^ conv2[i])
        c[i][i] = '0' + '1' - c[i][i];

  memset(conv1,0,sizeof(conv1));
  memset(conv2,0,sizeof(conv2));

  for (int i = n; i >= 0; i--)
    for (int j = 0; j < i; j++){
        if ((c[i][j] == '1') ^ conv1[i] ^ conv2[j]){
            cnt++;
            conv1[i] ^= 1;
            conv2[j] ^= 1;
        }       
    }

  for (int i = 0; i < n; i++)
    if (conv1[i] ^ conv2[i])
        c[i][i] = '0' + '1' - c[i][i];

  for (int i = 0; i < n; i++)
    if (c[i][i] == '1')
        cnt++;

  cout << cnt << endl;

  return 0;
}