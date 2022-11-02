var
  a,mas:array[0..100000] of int64; n,i,j:longint; ans:int64;


begin

  readln(n); for i:=1 to n do read(a[i]);
  mas[0]:=1;
  for i:=1 to 20 do mas[i]:=mas[i-1]*2;
  ans:=0;
  for i:=1 to n-1 do
  begin
    for j:=20 downto 0 do if i+mas[j]<=n then
    begin
      a[i+mas[j]]:=a[i+mas[j]]+a[i];
      ans:=ans+a[i]; break;
    end;
    writeln(ans);
  end;

end.