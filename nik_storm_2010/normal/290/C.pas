var
    win,res,i,x:longint; ans:extended;


begin

  readln(x);
  ans:=0; win:=0;
  for i:=1 to x do
    begin
      read(res); win:=win+res;
      if win/i>ans then ans:=win/i;
    end;
  writeln(ans:0:6);

end.