#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int n;
    cin >> n;
    int count=1,i;
    for(i = 2; i*i<n; i++)
    {
        if(n%i==0)
            count+=2;
    }
    if(i*i==n)
            count+=1;
    cout<<count<<endl;
    return 0;
}