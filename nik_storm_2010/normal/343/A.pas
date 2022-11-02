var
  ans,x,y,a,b:qword;

begin
  readln(a,b); ans:=1;
  while not((a=1) and (b=1)) do
  begin
    if (a>b) then
    begin
      if (a-b) mod b=0 then x:=(a-b) div b else x:=(a-b) div b+1;
      a:=a-x*b;
      ans:=ans+x;
    end
      else
    begin
      if (b-a) mod a=0 then x:=(b-a) div a else x:=(b-a) div a+1;
      b:=b-x*a;
      ans:=ans+x;
    end;
  end;
  writeln(ans);
end.