#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <stdio.h>
#include <sstream>
#include <math.h>
#include <set>
#include <queue>


using namespace std;
typedef long long ll;
int n,m,k,c1,c2,c3,c4,c5,l;
int ya,x1,y2,x2;
int suc;

std::map<int,int> M;
std::queue<int> q;
void dfs(int xf,int yf){

q.push(yf*1000+xf);
while(q.size()!=0){

int q2,x,y;
q2=q.front();
q.pop();
x=q2%1000;
y=int((q2-x)/1000);




if(x==x2 && y==y2){
    suc=0;
    if(x>0){if(M[1000*y+x-1] == 0){suc=1;}}
    if(x<m-1){if(M[1000*y+x+1] == 0){suc=1;}}
    if(y>0){if(M[1000*(y-1)+x] == 0){suc=1;}}
    if(y<n-1){if(M[1000*(y+1)+x] == 0){suc=1;}}

    if(suc==1){c5=1;return;}

}

else{

    if(x>0){if(M[1000*y+x-1] == 0){q.push(y*1000+x-1);M[y*1000+x-1]=1;}else{if(y==y2 && x-1==x2){c5=1;return;}}}
    if(x<m-1){if(M[1000*y+x+1] == 0){q.push(y*1000+x+1);M[y*1000+x+1]=1;}else{if(y==y2 && x+1==x2){c5=1;return;}}}
    if(y>0){if(M[1000*(y-1)+x] == 0){q.push((y-1)*1000+x);M[(y-1)*1000+x]=1;}else{if(y-1==y2 && x==x2){c5=1;return;}}}
    if(y<n-1){if(M[1000*(y+1)+x] == 0){q.push((y+1)*1000+x);M[(y+1)*1000+x]=1;}else{if(y+1==y2 && x==x2){c5=1;return;}}}



}

}


}



int main()
{



string s;

std::cin >> n;
std::cin >> m;

for(c1=0;c1<n;c1++){

    std::cin >> s;
    for(c2=0;c2<m;c2++){

        if(s[c2]=='.'){M[c1*1000+c2]=0;}
        else{M[c1*1000+c2]=1;}


    }

}

std::cin >> ya;
std::cin >> x1;
std::cin >> y2;
std::cin >> x2;
x2--;
x1--;
ya--;
y2--;

c5=0;



dfs(x1,ya);

if(c5==0){std::cout << "NO\n";}else{std::cout << "YES\n";}


    return 0;
}