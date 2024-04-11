import std.stdio; 
int main(){
    int n;
    long c1 , c2;
	scanf("%d %lld %lld" , &n , &c1 , &c2);
	char arr;
	int zeroes = 0;
    int ones = 0;
	for(int i = 0 ; i < n ; ++i){
	    scanf(" %c" , &arr);
	    if(arr == '0'){
	        ++zeroes;
	    }
	    else{
	        ++ones;
	    }
	}
	long ans = 800000000000000000L;
	for(long i = 1 ; i <= ones ; ++i){
	    long res = 0L;
	    res += 1L * c1 * i;
	    long small = n / i;
	    long large = small + 1L;
	    long largecnt = n % i;
	    long smallcnt = i - largecnt;
	    res += 1L * c2 * (small - 1L) * (small - 1L) * smallcnt;
	    res += 1L * c2 * (large - 1L) * (large - 1L) * largecnt;
	    if(res < ans){
	        ans = res;
	    }
	}
	printf("%lld" , ans);
	return 0;
}