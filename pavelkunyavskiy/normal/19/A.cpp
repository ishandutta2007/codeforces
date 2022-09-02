#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <iterator>
#include <stack>
#include <algorithm>
#include <cassert>

#define pb push_back
#define mp make_pair
#define all(a) (a.begin(),a.end())

#define taskname "A"

using namespace std;

typedef long long int64;
typedef long double ld;

map<string,int> num;

int score;

string name[10000];

int win[1000];
int goal[1000];
int razn[1000];

bool cmp(int a,int b){
    if (win[a]!=win[b])
        return win[a]>win[b];
    if (razn[a]!=razn[b])
        return razn[a]>razn[b];
    return goal[a]>goal[b];
}

bool cmplex(int a,int b){
    return name[a]<name[b];
}

int por[100];



int main(){

    int n;
    scanf("%d\n",&n);
    for (int i=0;i<n;i++)
    {
        string s;
        getline(cin,s);
        name[i]=s;
        num.insert(mp(s,i));
    }
    
    for (int i=0;i<(n*(n-1))/2;i++){
        string name1,name2;
        getline(cin,name1,'-');
        cin>>name2;
        int sc1,sc2;
        scanf(" %d:%d\n",&sc1,&sc2);
        goal[num[name1]]+=sc1;
        goal[num[name2]]+=sc2;
        razn[num[name2]]+=sc2-sc1;
        razn[num[name1]]+=sc1-sc2;
        win[num[name1]]+=(sc1>sc2)*3+(sc1==sc2);
        win[num[name2]]+=(sc2>sc1)*3+(sc1==sc2);
    }
    
    for (int i=0;i<n;i++)
        por[i]=i;
    sort(por,por+n,cmp);   
    sort(por,por+n/2,cmplex);
    for (int i=0;i<n/2;i++)
        cout<<name[por[i]]<<endl;
    
//  for (int i=0;i<4;i++)
        //cerr<<win[i]<<" "<<goal[i]<<" "<<razn[i]<<endl;
    
    return 0;
}