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
    int count_U = 0;
    int count_R=0;
    int answer=0;
    string input;
    cin>>input;
    if(input[0]=='U')
    {
        count_U++;
    }
    else
    {
        count_R++;
    }
    for(int i = 1; i<n-1; i++)
    {
        if(input[i]=='U')
            count_U++;
        else
            count_R++;
        if((count_U==count_R)&&(input[i]==input[i+1]))
            answer++;
    }
    cout<<answer<<endl;
    return 0;
}