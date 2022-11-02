#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar()-48, (c>9)&(c!=253));
	for(a=(b=c==253)?0:c; (c=getchar()-48)<=9; a=a*10+c);
	return b?-a:a;
}
auto rd=read<int>;
auto rd64=read<s64>;

s64 a[8], b[8], c[8], d[8], x, y, z;
s64 halff(s64 n) {return (n-(n&1))/2;}
s64 halfc(s64 n) {return (n+(n&1))/2;}
bool check(s64 m) {
	for(int i=0; i<2; ++i) {
		s64 al=halfc(d[1]-m-i), ar=halff(m-d[6]-i);
		s64 bl=halfc(d[2]-m-i), br=halff(m-d[5]-i);
		s64 cl=halfc(d[4]-m-i), cr=halff(m-d[3]-i);
		s64 sl=halfc(d[0]-m-3*i), sr=halff(m-d[7]-3*i);
		if(al<=ar&&bl<=br&&cl<=cr&&sl<=sr&&al+bl+cl<=sr&&sl<=ar+br+cr) {
			s64 a=al, b=bl, c=cl;
			if(a+b+c<sl) {
				if(ar+b+c>=sl) {
					a=sl-b-c;
				} else {
					a=ar;
					if(a+br+c>=sl) {
						b=sl-a-c;
					} else {
						b=br;
						c=sl-a-b;
					}
				}
			}
			x=b+c+i;
			y=a+c+i;
			z=a+b+i;
			return true;
		}
	}
	return false;
}
void work() {
	int n=rd();
	memset(d, 192, sizeof(d));
	while(n--) {
		s64 x=rd64(), y=rd64(), z=rd64();
		for(int i=0; i<8; ++i) cmax(d[i], -a[i]*x-b[i]*y-c[i]*z);
	}
	s64 l=0, r=3e18;
	while(l<r) {
		s64 mid=(l+r)/2;
		if(check(mid)) r=mid; else l=mid+1;
	}
	check(l);
	printf("%lld %lld %lld\n", x, y, z);
}
int main() {
	int t=rd();
	for(int i=0; i<8; ++i) {
		a[i]=(i  &1)*2-1;
		b[i]=(i/2&1)*2-1;
		c[i]=(i/4&1)*2-1;
	}
	while(t--) work();
	return 0;
}