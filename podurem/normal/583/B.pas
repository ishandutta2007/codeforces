var
	a: array[1..1007] of longint;
	ans, i, n, kol: longint;
	
BEGIN
	readln(n);
	for i := 1 to n do
		read(a[i]);
	kol := 0;
	ans := 0;
	while kol <> n do
		begin
			for i := 1 to n do
				if a[i] <= kol then
					begin
						inc(kol);
						a[i] := n + 10;
					end;
			if kol <> n then
				inc(ans);
			for i := n downto 1 do
				if a[i] <= kol then
					begin
						inc(kol);
						a[i] := n + 10;
					end;
			if kol <> n then
				inc(ans);
		end;
	writeln(ans);
END.