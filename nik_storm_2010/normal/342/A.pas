var
  a:array[1..7] of longint; n,c,i:longint;


begin
  readln(n);
  for i:=1 to n do
  begin
    read(c);
    inc(a[c]);
  end;
  if (a[7]>0) or (a[5]>0) or (a[1]<>n div 3) or (a[3]>a[6]) then begin writeln(-1); halt; end;
  a[6]:=a[6]-a[3];
  if (a[2]<>a[4]+a[6]) then begin writeln(-1); halt; end;
  for i:=1 to a[3] do writeln(1,' ',3,' ',6);
  for i:=1 to a[6] do writeln(1,' ',2,' ',6);
  for i:=1 to a[4] do writeln(1,' ',2,' ',4);
end.