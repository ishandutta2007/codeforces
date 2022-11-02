Var
   i,n,t: longint;



Begin

  assign(input,'input.txt');
   assign(output,'output.txt');
    reset(input);
     rewrite(output);
      readln(t);
       for i:=1 to t do
        begin
         readln(n);
          if (odd(n)) = true then writeln(0)
                             else writeln(1);
        end;
   close(input);
  close(output);

End.