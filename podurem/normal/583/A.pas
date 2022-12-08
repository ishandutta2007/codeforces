var
	g, v: array[1..58] of boolean; 
	n, i, x, y: longint;

BEGIN
	readln(n);
	for i := 1 to n do
		begin
			g[i] := false;
			v[i] := false;
		end;
	for i := 1 to n * n do
		begin
			readln(x, y);
			if (g[x] = false) and (v[y] = false) then
				begin
					writeln(i);
					g[x] := true;
					v[y] := true;
				end;
		end;
END.