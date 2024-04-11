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

const string names[5]={"S","M","L","XL","XXL"};

int getsize(string name){
    for (int i=0;i<5;i++)
    if (names[i]==name)
        return i;
    assert(false);
}

int have[5];

int main(){
    for (int i=0;i<5;i++)
    cin>>have[i];
    int k;
    scanf("%d",&k);    
    for (int i=0;i<k;i++){
    string s;
    cin>>s; 
    int want=getsize(s);
    //cerr<<want<<endl;
    for (int d=0;d<5;d++){
        //cerr<<want+d<<endl;
        if (want+d<5 && have[want+d]>0){
        cout<<names[want+d]<<endl;
        have[want+d]--;
        break;
        }
        if (want-d>=0 && have[want-d]>0){
        cout<<names[want-d]<<endl;
        have[want-d]--;
        break;
        }
    }
    }
    return 0;  
}