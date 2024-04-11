#include <set>
#include <cstdio>
using namespace std;
set<int> pos;
multiset<int> ans;
int n,q;
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		int p;
		scanf("%d",&p);
		pos.insert(p);
	}
	if(n>1){
		set<int>::iterator it_1,it_2;
		it_1=it_2=pos.begin();
		it_2++;
		while(it_2!=pos.end()){
			ans.insert((*it_2)-(*it_1));
			it_1++;
			it_2++;
		}
	}
	if(n<=2){
		puts("0");
	}
	else{
		printf("%d\n",(*(--pos.end())-*pos.begin())-(*(--ans.end())));
	}
	for(int i=1;i<=q;i++){
		int op,x;
		scanf("%d",&op);
		if(op==0){
			scanf("%d",&x);
			set<int>::iterator it_1,it_2,it_3;
			it_1=pos.find(x);
			if(it_1!=pos.begin()){
				it_2=it_1;
				it_2--;
				ans.erase(ans.find((*it_1)-(*it_2)));
			}
			it_3=it_1;
			it_3++;
			if(it_3!=pos.end()){
				ans.erase(ans.find((*it_3)-(*it_1)));
			}
			if(it_1!=pos.begin()&&it_3!=pos.end()){
				ans.insert((*it_3)-(*it_2));
			}
			pos.erase(it_1);
		}
		else{
			scanf("%d",&x);
			set<int>::iterator it_1,it_2,it_3;
			pos.insert(x);
			it_1=pos.find(x);
			if(it_1!=pos.begin()){
				it_2=it_1;
				it_2--;
				ans.insert((*it_1)-(*it_2));
			}
			it_3=it_1;
			it_3++;
			if(it_3!=pos.end()){
				ans.insert((*it_3)-(*it_1));
			}
			if(it_1!=pos.begin()&&it_3!=pos.end()){
				ans.erase(ans.find((*it_3)-(*it_2)));
			}
		}
		if(pos.size()<=2){
			puts("0");
		}
		else{
			printf("%d\n",(*(--pos.end())-*pos.begin())-(*(--ans.end())));
		}
	}
	return 0;
}