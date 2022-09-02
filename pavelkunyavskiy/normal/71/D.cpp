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

string a[100][100];
bool good[100][100];
int n,m;

bool check(int x,int y){
    if (x+2 >= n  || y+2 >= m)
        return false;
    bool q = true;
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            q &= (a[x+i][y+j][1] == a[x][y][1]);
    if (q)
        return true;
        
    q=true;
        
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            for (int i1=0;i1<3;i1++)
                for (int j1=0;j1<3;j1++)        
                    q &= ((i==i1 && j==j1) || (a[x+i][y+j][0] != a[x+i1][y+j1][0]));
    return q;
}

bool check(int& x1,int& y1,int& x2,int& y2){
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            good[i][j] = check(i,j);
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            for (int i1=0;i1<n;i1++)
                for (int j1=0;j1<m;j1++)
                    if (good[i][j] && good[i1][j1])
                        if ((min(i1+2,i+2) < max(i,i1)) || (min(j1+2,j+2) < max(j,j1))){
                            x1=i;y1=j;
                            x2=i1;y2=j1;
                            return true;
                        }
    return false;                       
}

int jx1,jx2,jy1,jy2;
set<string> scards;
string cards[100];
int cnt;

const char cfirst[13] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
const char csecond[4] = {'C', 'D', 'H', 'S'};

void solvenojok(){
    int x,y,x1,y1;
    if (!check(x,y,x1,y1))
        printf("No solution.\n");
    else {
        printf("Solution exists.\n");
        printf("There are no jokers.\n");
        printf("Put the first square to (%d, %d).\n",x+1,y+1);      
        printf("Put the second square to (%d, %d).\n",x1+1,y1+1);       
    }       
}

void solveonejok(int num,int X,int Y){
    for (int i=0;i<cnt;i++){
        a[X][Y] = cards[i];
        int x,y,x1,y1;
        if (check(x,y,x1,y1)){
            printf("Solution exists.\n");
            printf("Replace J%d with %s.\n",num,cards[i].data());
            printf("Put the first square to (%d, %d).\n",x+1,y+1);      
            printf("Put the second square to (%d, %d).\n",x1+1,y1+1);
            return; 
        }   
    }
    printf("No solution.\n");
}

void solvetwojok(int X,int Y,int X1,int Y1){
    for (int i=0;i<cnt;i++)
        for (int j=0;j<cnt;j++)
            if (i!=j){
                a[X][Y] = cards[i];
                a[X1][Y1] = cards[j];
                int x,y,x1,y1;
                if (check(x,y,x1,y1)){
                    printf("Solution exists.\n");
                    printf("Replace J1 with %s and J2 with %s.\n",cards[i].data(),cards[j].data());
                    printf("Put the first square to (%d, %d).\n",x+1,y+1);      
                    printf("Put the second square to (%d, %d).\n",x1+1,y1+1);
                    return; 
                }   
            }
    printf("No solution.\n");
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    cin>>n>>m;
    jx1=jx2=-1;
    for (int i=0;i<13;i++)
        for (int j=0;j<4;j++)
            scards.insert(string("")+cfirst[i]+csecond[j]);
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++){
            cin>>a[i][j];
            if (a[i][j][1] == '1'){
                jx1=i;jy1=j;
            }
            if (a[i][j][1] == '2'){
                jx2=i;jy2=j;
            }
            scards.erase(a[i][j]);
        }
    copy(scards.begin(),scards.end(),cards);
    cnt = scards.size();
    if (jx1 == -1 && jx2 == -1)
        solvenojok();
    else if (jx1 != -1 && jx2 != -1)
        solvetwojok(jx1,jy1,jx2,jy2);
    else if (jx1 != -1)
        solveonejok(1,jx1,jy1);
    else 
        solveonejok(2,jx2,jy2);
    return 0;
}