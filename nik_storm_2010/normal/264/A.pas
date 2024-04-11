var
    a:array[1..1000000] of longint; s:ansistring; l,r,d,i:longint;


begin

  readln(s); d:=length(s); l:=1; r:=d;
  for i:=1 to d do
    begin
      if s[i]='l' then begin a[r]:=i; dec(r); end
                  else begin a[l]:=i; inc(l); end;
    end;
  for i:=1 to d do writeln(a[i]);

end.