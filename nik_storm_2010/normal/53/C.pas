Var
    n,left,right: longint;


Begin

  readln(n);
   left:=1;
    right:=n;
     while right>left do
      begin
       write(left,' ');
        write(right,' ');
         inc(left);
          dec(right);
      end;
  if left=right
   then write(left,' ');

End.