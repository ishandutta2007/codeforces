var
    a:array[0..100000] of longint; n,k,i,ans:longint; may:boolean;

begin

  readln(n,k); for i:=1 to n do read(a[i]);

  may:=true;
  for i:=k to n do if a[i]<>a[k] then may:=false;
  if may=true then
    begin
      a[0]:=0;
      for i:=n downto 0 do
        if a[i]<>a[n] then begin ans:=i; break; end;
      writeln(ans);
    end
    else writeln(-1);

end.