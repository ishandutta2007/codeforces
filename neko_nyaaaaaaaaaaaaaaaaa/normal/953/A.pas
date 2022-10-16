var l,r,ans,i,j,k,a,b:int64;

begin
	ans := 0;
	read(l, r);
	for i:=0 to 30 do
		begin
		for j:=0 to 20 do
			begin
			k:=1;
			if i<>0 then
				for a:=1 to i do k:=k*2;
			if j<>0 then
				for b:=1 to j do k:=k*3;
			if k >= l then
				if k <= r then 
				begin
				ans:=ans+1;
				end;
			
			end;
		end;
	write(ans);
end.