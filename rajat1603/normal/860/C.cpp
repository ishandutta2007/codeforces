#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
char str[N][10];
int type[N];
vector < int > wtf;
vector < int > fix;
vector < int > rekt[2];
int val[N];
set < int > there;
int e;
vector < pair < string , string > > v;
int main(){
	scanf("%d" , &n);
	e = 0;
	for(int i = 1 ; i <= n ; ++i){
		scanf("%s" , str[i]);
		scanf("%d" , type + i);
		e += type[i];
	}
	for(int i = 1 ; i <= n ; ++i){
		int num = 0;
		for(int j = 0 ; str[i][j] ; ++j){
			if(isdigit(str[i][j])){
				num *= 10;
				num += str[i][j] - '0';
			}
			else{
				num = -1;
				break;
			}
		}
		if(num < 1 || num > n){
			num = -1;
		}
		if(str[i][0] == '0'){
			num = -1;
		}
		val[i] = num;
		if(num == -1){
			wtf.emplace_back(i);
		}
		else{
			there.insert(num);
			if(type[i] == 1 && num <= e){
				fix.emplace_back(i);
			}
			else if(type[i] == 0 && num > e){
				fix.emplace_back(i);
			}
			else{
				rekt[type[i]].emplace_back(i);
			}
		}
	}
	if(rekt[0].empty() && rekt[1].empty()){

	}
	else{
		if(there.size() == n){
			int x;
			if(!rekt[0].empty()){
				x = rekt[0].back();
				rekt[0].pop_back();
			}
			else{
				x = rekt[1].back();
				rekt[1].pop_back();
			}
			there.erase(val[x]);
			v.push_back({str[x] , "random"});
			str[x][0] = 'r';
			str[x][1] = 'a';
			str[x][2] = 'n';
			str[x][3] = 'd';
			str[x][4] = 'o';
			str[x][5] = 'm';
			val[x] = -1;
			wtf.emplace_back(x);
		}
	}
	set < int > canuse;
	canuse.clear();
	for(int i = 1 ; i <= n ; ++i){
		canuse.insert(i);
	}
	for(int x : there){
		canuse.erase(x);
	}
	while(!(rekt[0].empty() && rekt[1].empty())){
		if(!rekt[1].empty() && *canuse.begin() <= e){
			v.push_back({str[rekt[1].back()] , to_string(*canuse.begin())});
			canuse.erase(canuse.begin());
			canuse.insert(val[rekt[1].back()]);
			rekt[1].pop_back();
		}
		else if(!rekt[0].empty() && *prev(canuse.end()) > e){
			v.push_back({str[rekt[0].back()] , to_string(*prev(canuse.end()))});
			canuse.erase(prev(canuse.end()));
			canuse.insert(val[rekt[0].back()]);
			rekt[0].pop_back();
		}
	}
	for(int x : wtf){
		if(type[x] == 1){
			v.push_back({str[x] , to_string(*canuse.begin())});
			canuse.erase(canuse.begin());
		}
		else{
			v.push_back({str[x] , to_string(*prev(canuse.end()))});
			canuse.erase(prev(canuse.end()));
		}
	}
	printf("%d\n" , int(v.size()));
	for(auto it : v){
		cout << "move " << it.first << " " << it.second << endl;
	}
}