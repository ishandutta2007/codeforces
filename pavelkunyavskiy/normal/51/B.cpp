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

typedef long long int64;
typedef long double ld;

enum lexem {_ta,_taend,_tr,_trend,_td,_tdend,_end};

string s;

struct _curent{
    lexem cur;
    int pos;
    void next();
} curent;

bool checknext(int pos,const string& temp){
    for (int i=0;i<temp.size();i++){
        if (pos+i >= s.size())
            return false;
        if (s[pos+i]!=temp[i])
            return false;
    }
//  cerr<<"!!!"<<temp<<endl;
    return true;
}

void _curent::next(){
    if (pos==s.size()){
        cur=_end;
        return;
    }
//  cerr<<string(s.begin()+pos,s.end())<<endl;
    if (checknext(pos,"<table>")){
        cur=_ta;
        pos+=7;
        return;
    }
    if (checknext(pos,"</table>")){
        cur=_taend;
        pos+=8;
        return;
    }
    if (checknext(pos,"<td>")){
        cur=_td;
        pos+=4;
        return;
    }
    if (checknext(pos,"</td>")){
        cur=_tdend;
        pos+=5;
        return;
    }
    if (checknext(pos,"<tr>")){
        cur=_tr;
        pos+=4;
        return;
    }
    if (checknext(pos,"</tr>")){
        cur=_trend;
        pos+=5;
        return;
    }
    assert(false);
}

vector<int> answer;

int gettd();
int gettr();
void gettable();

int gettd(){
    //cerr<<"TD"<<endl;
    assert(curent.cur==_td);
    curent.next();
    if (curent.cur == _ta ){
//      curent.next();
        gettable();
    }
    assert(curent.cur == _tdend);
    curent.next();
//  cerr<<"|TD"<<endl;
    return 1;
}

int gettr(){
    assert(curent.cur==_tr);
    curent.next();
    int cnt=0;
    while (curent.cur == _td){
        cnt+=gettd();
    }
    assert(curent.cur == _trend);
    curent.next();
    return cnt;
}

void gettable(){
    assert(curent.cur==_ta);
    int ans=0;
    curent.next();
    while (curent.cur == _tr){
        ans+=gettr();

    }
    assert(curent.cur==_taend);
    curent.next();
    answer.pb(ans);
}

void read(){    
    for (char c;scanf(" %c ",&c)==1;)
        s+=c;
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    read();
    curent.pos=0;
    curent.next();
    gettable();
    assert(curent.cur==_end);
    sort(answer.begin(),answer.end());
    for (int i=0;i<answer.size();i++)
        printf("%d%c",answer[i]," \n"[i+1==answer.size()]);
    return 0;
}