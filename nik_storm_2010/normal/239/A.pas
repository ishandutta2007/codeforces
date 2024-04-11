var
    y,x,k,n,i:int64; have:boolean;


begin

  readln(y,k,n); i:=k; have:=false;
  while i<=n do
    begin
      x:=i-y;
      if x>=1 then
        begin
          have:=true; write(x,' ');
        end;
      i:=i+k;
    end;
  if have=false then writeln(-1);

end.